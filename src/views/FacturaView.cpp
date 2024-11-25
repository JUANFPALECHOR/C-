#include "FacturaView.h"
#include "Utils.h" // Asegúrate de incluir Utils.h para la validación de fechas
#include <iostream>
#include <limits>
#include <memory>
#include <algorithm>

using namespace std;

FacturaView::FacturaView(FacturaController& facturaCtrl,
                         EmpleadoController& empleadoCtrl,
                         ClienteController& clienteCtrl,
                         ProveedorController& proveedorCtrl,
                         ProductoController& productoCtrl)
    : facturaCtrl(facturaCtrl),
      empleadoCtrl(empleadoCtrl),
      clienteCtrl(clienteCtrl),
      proveedorCtrl(proveedorCtrl),
      productoCtrl(productoCtrl) {}

void FacturaView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Facturas ---\n";
        cout << "1. Crear Factura de Venta\n";
        cout << "2. Crear Factura de Compra\n";
        cout << "3. Generar Reporte de Total de Ventas Mensuales\n";
        cout << "4. Generar Reporte de Meses con Mayores Ventas\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            continue;
        }

        switch(opcion) {
            case 1:
                crearFacturaVenta();
                break;
            case 2:
                crearFacturaCompra();
                break;
            case 3:
                generarReporteTotalVentasMensuales();
                break;
            case 4:
                generarReporteMesesConMayoresVentas();
                break;
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while(opcion != 5);
}

void FacturaView::crearFacturaVenta() {
    int idFactura, idEmpleado, idCliente;
    FechaHora fechaHora;
    TipoFactura tipoFactura = TipoFactura::VENTA;

    // Generar el siguiente ID de Factura utilizando el controlador
    idFactura = facturaCtrl.generarSiguienteId();

    cout << "Ingrese el ID del Empleado: ";
    cin >> idEmpleado;
    if (cin.fail() || empleadoCtrl.obtenerPorId(idEmpleado) == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Empleado inválido.\n";
        return;
    }

    cout << "Ingrese el ID del Cliente: ";
    cin >> idCliente;
    if (cin.fail() || clienteCtrl.obtenerPorId(idCliente) == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Cliente inválido.\n";
        return;
    }

    // Solicitar la fecha al usuario
    cout << "Ingrese la fecha de la factura:\n";
    cout << "Día (1-31): ";
    cin >> fechaHora.dia;
    cout << "Mes (1-12): ";
    cin >> fechaHora.mes;
    cout << "Año (e.g., 2024): ";
    cin >> fechaHora.año;
    cout << "Hora (0-23): ";
    cin >> fechaHora.hora;
    cout << "Minuto (0-59): ";
    cin >> fechaHora.minuto;
    cout << "Segundo (0-59): ";
    cin >> fechaHora.segundo;

    // Validar la fecha ingresada
    if (cin.fail() || !esFechaValida(fechaHora)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Fecha u hora inválida.\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    // Crear la factura
    shared_ptr<Factura> factura = make_shared<Factura>(
        idFactura, fechaHora, tipoFactura, idEmpleado, idCliente, 0
    );

    // Añadir detalles a la factura
    while (true) {
        int idProducto, cantidad;
        double valorProducto;

        cout << "Ingrese el ID del Producto (0 para finalizar): ";
        cin >> idProducto;
        if (cin.fail() || idProducto < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ID de producto inválido.\n";
            continue;
        }

        if (idProducto == 0) break; // Finalizar detalles

        auto producto = productoCtrl.obtenerProductoPorId(idProducto);
        if (producto == nullptr) {
            cout << "Error: Producto con ID " << idProducto << " no encontrado.\n";
            continue;
        }

        cout << "Ingrese la cantidad: ";
        cin >> cantidad;
        if (cin.fail() || cantidad <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Cantidad inválida.\n";
            continue;
        }

        // Obtener el valor actual del producto
        valorProducto = producto->getPrecio();

        // Crear DetalleFactura
        int idDetalle = factura->getDetalles().size() + 1;
        shared_ptr<DetalleFactura> detalle = make_shared<DetalleFactura>(
            idDetalle, idFactura, idProducto, valorProducto, cantidad
        );

        factura->addDetalle(detalle);
    }

    // Verificar que la factura tenga al menos un detalle
    if (factura->getDetalles().empty()) {
        cout << "Error: La factura debe tener al menos un producto.\n";
        return;
    }

    // Crear la factura de venta
    if (facturaCtrl.crearFacturaVenta(factura)) {
        cout << "Factura de venta creada exitosamente con ID " << idFactura << ".\n";
        cout << "Total de la Factura: $" << factura->calcularTotal() << "\n";
    } else {
        cout << "Error: No se pudo crear la factura de venta. Verifique los detalles.\n";
    }
}

void FacturaView::crearFacturaCompra() {
    int idFactura, idEmpleado, idProveedor;
    FechaHora fechaHora;
    TipoFactura tipoFactura = TipoFactura::COMPRA;

    // Generar el siguiente ID de Factura utilizando el controlador
    idFactura = facturaCtrl.generarSiguienteId();

    cout << "Ingrese el ID del Empleado: ";
    cin >> idEmpleado;
    if (cin.fail() || empleadoCtrl.obtenerPorId(idEmpleado) == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Empleado inválido.\n";
        return;
    }

    cout << "Ingrese el ID del Proveedor: ";
    cin >> idProveedor;
    if (cin.fail() || proveedorCtrl.obtenerPorId(idProveedor) == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Proveedor inválido.\n";
        return;
    }

    // Solicitar la fecha al usuario
    cout << "Ingrese la fecha de la factura:\n";
    cout << "Día (1-31): ";
    cin >> fechaHora.dia;
    cout << "Mes (1-12): ";
    cin >> fechaHora.mes;
    cout << "Año (e.g., 2024): ";
    cin >> fechaHora.año;
    cout << "Hora (0-23): ";
    cin >> fechaHora.hora;
    cout << "Minuto (0-59): ";
    cin >> fechaHora.minuto;
    cout << "Segundo (0-59): ";
    cin >> fechaHora.segundo;

    // Validar la fecha ingresada
    if (cin.fail() || !esFechaValida(fechaHora)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Fecha u hora inválida.\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    // Crear la factura
    shared_ptr<Factura> factura = make_shared<Factura>(
        idFactura, fechaHora, tipoFactura, idEmpleado, 0, idProveedor
    );

    // Añadir detalles a la factura
    while (true) {
        int idProducto, cantidad;
        double valorProducto;

        cout << "Ingrese el ID del Producto (0 para finalizar): ";
        cin >> idProducto;
        if (cin.fail() || idProducto < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ID de producto inválido.\n";
            continue;
        }

        if (idProducto == 0) break; // Finalizar detalles

        auto producto = productoCtrl.obtenerProductoPorId(idProducto);
        if (producto == nullptr) {
            cout << "Error: Producto con ID " << idProducto << " no encontrado.\n";
            continue;
        }

        cout << "Ingrese la cantidad: ";
        cin >> cantidad;
        if (cin.fail() || cantidad <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Cantidad inválida.\n";
            continue;
        }

        // Obtener el valor actual del producto
        valorProducto = producto->getPrecio();

        // Crear DetalleFactura
        int idDetalle = factura->getDetalles().size() + 1;
        shared_ptr<DetalleFactura> detalle = make_shared<DetalleFactura>(
            idDetalle, idFactura, idProducto, valorProducto, cantidad
        );

        factura->addDetalle(detalle);
    }

    // Verificar que la factura tenga al menos un detalle
    if (factura->getDetalles().empty()) {
        cout << "Error: La factura debe tener al menos un producto.\n";
        return;
    }

    // Crear la factura de compra
    if (facturaCtrl.crearFacturaCompra(factura)) {
        cout << "Factura de compra creada exitosamente con ID " << idFactura << ".\n";
        cout << "Total de la Factura: $" << factura->calcularTotal() << "\n";
    } else {
        cout << "Error: No se pudo crear la factura de compra. Verifique los detalles.\n";
    }
}

// Métodos de reporte

void FacturaView::generarReporteTotalVentasMensuales() {
    int mes, año;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el año (e.g., 2024): ";
    cin >> año;

    if (cin.fail() ||
        mes < 1 || mes > 12 ||
        año < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Mes o año inválido.\n";
        return;
    }

    double totalVentas = facturaCtrl.calcularTotalVentasMensuales(mes, año);
    cout << "Total de Ventas en " << mes << "/" << año << ": $" << totalVentas << "\n";
}

void FacturaView::generarReporteMesesConMayoresVentas() {
    int año;
    cout << "Ingrese el año (e.g., 2024): ";
    cin >> año;

    if (cin.fail() || año < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Año inválido.\n";
        return;
    }

    auto ventasPorMes = facturaCtrl.obtenerVentasPorMes(año);
    if (ventasPorMes.empty()) {
        cout << "No hay ventas registradas para el año " << año << ".\n";
        return;
    }

    // Encontrar el mayor total de ventas
    double maxVentas = 0.0;
    for (const auto& [mes, total] : ventasPorMes) {
        if (total > maxVentas) {
            maxVentas = total;
        }
    }

    // Identificar los meses con el mayor total
    cout << "Mes(es) con mayores ventas en el año " << año << ":\n";
    for (const auto& [mes, total] : ventasPorMes) {
        if (total == maxVentas) {
            cout << "Mes: " << mes << ", Total Ventas: $" << total << "\n";
        }
    }
}
