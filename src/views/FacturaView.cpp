#include "FacturaView.h"
#include "Utils.h" 
#include <iostream>
#include <limits>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <iomanip>


using namespace std;

FacturaView::FacturaView(FacturaController& facturaCtrl,
                         EmpleadoController& empleadoCtrl,
                         ClienteController& clienteCtrl,
                         ProveedorController& proveedorCtrl,
                         ProductoController& productoCtrl,
                         MarcaController& marcaCtrl)
    : facturaCtrl(facturaCtrl),
      empleadoCtrl(empleadoCtrl),
      clienteCtrl(clienteCtrl),
      proveedorCtrl(proveedorCtrl),
      productoCtrl(productoCtrl),
      marcaCtrl(marcaCtrl) {}

void FacturaView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Facturas ---\n";
        cout << "1. Crear Factura de Venta\n";
        cout << "2. Crear Factura de Compra\n";
        cout << "3. Generar Reporte de Total de Ventas Mensuales\n";
        cout << "4. Generar Reporte de Meses con Mayores Ventas\n";
        cout << "5. Mostrar Marca Más Vendida\n";
        cout << "6. Generar Reporte de Ganancias\n";
        cout << "7. Mostrar Facturas de Ventas por Mes\n"; 
        cout << "8. Buscar y Mostrar Factura por ID\n";
        cout << "9. Volver al Menú Principal\n";
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
                mostrarMarcaMasVendida();
                break;
            case 6:
                generarReporteGanancias();
                break;
            case 7:
                mostrarFacturasDeVentasPorMes(); 
                break;
            case 8:
                buscarYMostrarFacturaPorId(); 
                break;
            case 9:
                cout << "volviendo al menu..\n";
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while(opcion != 9);
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

void FacturaView::mostrarMarcaMasVendida() {
    // Mapa para acumular ventas por marca
    std::unordered_map<int, double> ventasPorMarca; 

    // Recorrer todas las facturas de venta
    for (const auto& factura : facturaCtrl.listarFacturas()) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            for (const auto& detalle : factura->getDetalles()) {
                int idProducto = detalle->getIdProducto();
                Producto* producto = productoCtrl.obtenerProductoPorId(idProducto);
                if (producto) {
                    int idMarca = producto->getIdMarca();
                    double subtotal = detalle->calcularSubtotal();
                    ventasPorMarca[idMarca] += subtotal;
                }
            }
        }
    }

    if (ventasPorMarca.empty()) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    // Encontrar la marca con mayor total de ventas
    int idMarcaMasVendida = -1;
    double maxVentas = 0.0;
    for (const auto& [idMarca, totalVentas] : ventasPorMarca) {
        if (totalVentas > maxVentas) {
            maxVentas = totalVentas;
            idMarcaMasVendida = idMarca;
        }
    }

    if (idMarcaMasVendida == -1) {
        cout << "No se pudo determinar la marca más vendida.\n";
        return;
    }

    Marca* marcaMasVendida = marcaCtrl.obtenerMarcaPorId(idMarcaMasVendida);
    if (marcaMasVendida) {
        cout << "\n--- Marca Más Vendida ---\n";
        cout << "ID: " << marcaMasVendida->getIdMarca() << "\n";
        cout << "Nombre: " << marcaMasVendida->getNombreMarca() << "\n";
        cout << "Total Ventas: $" << maxVentas << "\n";
    } else {
        cout << "Error: Marca con ID " << idMarcaMasVendida << " no encontrada.\n";
    }
}

void FacturaView::generarReporteGanancias() {
    int cantidadVentas = 0;
    double totalVentas = 0.0;

    int cantidadCompras = 0;
    double totalCompras = 0.0;

    // Recorrer todas las facturas
    for (const auto& factura : facturaCtrl.listarFacturas()) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            cantidadVentas++;
            totalVentas += factura->calcularTotal();
        } else if (factura->getTipoFactura() == TipoFactura::COMPRA) {
            cantidadCompras++;
            totalCompras += factura->calcularTotal();
        }
    }

    // Mostrar los resultados
    cout << "\n--- Reporte de Ganancias ---\n";
    cout << "Facturas de Venta:\n";
    cout << "Cantidad: " << cantidadVentas << "\n";
    cout << "Total Ventas: $" << totalVentas << "\n\n";

    cout << "Facturas de Compra:\n";
    cout << "Cantidad: " << cantidadCompras << "\n";
    cout << "Total Compras: $" << totalCompras << "\n\n";

    double ganancias = totalVentas - totalCompras;
    cout << "Ganancias Totales: $" << ganancias << "\n";
}

void FacturaView::mostrarFacturasDeVentasPorMes() {
    int mes, anio;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el año (e.g., 2023): ";
    cin >> anio;

    if (cin.fail() || mes < 1 || mes > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Por favor, ingrese un mes válido.\n";
        return;
    }

    vector<shared_ptr<Factura>> facturas = facturaCtrl.listarFacturas();

    // Filtrar las facturas de venta del mes y año indicados
    vector<shared_ptr<Factura>> facturasFiltradas;

    for (const auto& factura : facturas) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            FechaHora fechaHoraFactura = factura->getFechaHora();
            int facturaMes = fechaHoraFactura.mes;
            int facturaAnio = fechaHoraFactura.año;

            if (facturaMes == mes && facturaAnio == anio) {
                facturasFiltradas.push_back(factura);
            }
        }
    }

    if (facturasFiltradas.empty()) {
        cout << "No hay facturas de venta registradas para el mes " << mes << " del año " << anio << ".\n";
        return;
    }

    // Mostrar las facturas filtradas
    cout << "\n--- Facturas de Venta del Mes " << mes << " del Año " << anio << " ---\n";
    cout << "ID\tFecha\t\tHora\t\tValor Total\tID Empleado\tID Cliente\n";
    for (const auto& factura : facturasFiltradas) {
        int idFactura = factura->getIdFactura();
        FechaHora fechaHoraFactura = factura->getFechaHora();
        double valorTotal = factura->calcularTotal();
        int idEmpleado = factura->getIdEmpleado();
        int idCliente = factura->getIdCliente();

        // Formatear fecha y hora
        char fechaStr[11];
        snprintf(fechaStr, sizeof(fechaStr), "%02d/%02d/%04d",
                 fechaHoraFactura.dia, fechaHoraFactura.mes, fechaHoraFactura.año);

        char horaStr[9];
        snprintf(horaStr, sizeof(horaStr), "%02d:%02d:%02d",
                 fechaHoraFactura.hora, fechaHoraFactura.minuto, fechaHoraFactura.segundo);

        cout << idFactura << "\t" << fechaStr << "\t" << horaStr << "\t$"
             << std::fixed << std::setprecision(2) << valorTotal << "\t\t"
             << idEmpleado << "\t\t" << idCliente << "\n";
    }
}

void FacturaView::buscarYMostrarFacturaPorId() {
    int idFactura;
    cout << "Ingrese el ID de la factura que desea buscar: ";
    cin >> idFactura;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
        return;
    }

    // Obtener la factura desde el controlador
    shared_ptr<Factura> factura = facturaCtrl.obtenerFacturaPorId(idFactura);

    if (!factura) {
        cout << "No se encontró una factura con el ID " << idFactura << ".\n";
        return;
    }

    // Mostrar los datos de la factura
    cout << "\n--- Detalles de la Factura ---\n";
    cout << "ID Factura: " << factura->getIdFactura() << "\n";
    cout << "Fecha: " << factura->getFechaHora().dia << "/"
         << factura->getFechaHora().mes << "/"
         << factura->getFechaHora().año << "\n";
    cout << "Hora: " << factura->getFechaHora().hora << ":"
         << factura->getFechaHora().minuto << ":"
         << factura->getFechaHora().segundo << "\n";
    cout << "Tipo de Factura: " << (factura->getTipoFactura() == TipoFactura::VENTA ? "Venta" : "Compra") << "\n";
    cout << "ID Empleado: " << factura->getIdEmpleado() << "\n";

    if (factura->getTipoFactura() == TipoFactura::VENTA) {
        cout << "ID Cliente: " << factura->getIdCliente() << "\n";
    } else {
        cout << "ID Proveedor: " << factura->getIdProveedor() << "\n";
    }

    // Mostrar los detalles de los productos en la factura
    cout << "\n--- Detalles de Productos ---\n";
    cout << "Descripción\tCantidad\tValor Unitario\tSubtotal\n";

    double subtotalFactura = 0.0;

    for (const auto& detalle : factura->getDetalles()) {
        int idProducto = detalle->getIdProducto();
        int cantidad = detalle->getCantidadProductos();
        double valorUnitario = detalle->getValorProducto();
        double subtotal = detalle->calcularSubtotal();
        subtotalFactura += subtotal;

        // Obtener la descripción del producto
        Producto* producto = productoCtrl.obtenerProductoPorId(idProducto);
        string descripcion = producto ? producto->getDescripcionProducto() : "Producto no encontrado";

        cout << descripcion << "\t" << cantidad << "\t\t$"
             << valorUnitario << "\t\t$" << subtotal << "\n";
    }

    // Mostrar el total de la factura
    double valorTotalFactura = factura->calcularTotal();

    cout << "\nSubtotal de la Factura: $" << subtotalFactura << "\n";
    cout << "Valor Total de la Factura: $" << valorTotalFactura << "\n";
}
