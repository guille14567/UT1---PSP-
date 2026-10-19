package controlador;

import java.time.DateTimeException;
import java.time.LocalDate;

import modelo.Factura;
import modelo.GestorFacturas;
import vista.Principal;

public class Controlador {

    private static Principal vista;
    private static GestorFacturas gestor;
    private static boolean editando = false;

    public Controlador() {
      
        this.gestor = new GestorFacturas();
    }
    
    public static void iniciar(){
        vista = new Principal();
        vista.setVisible(true);
        
    }

    public static void añadirOActualizar() {

        try {
            String asunto = vista.getAsunto();

            int dia = vista.getDia();
            int mes = vista.getMes();
            int año = vista.getAño();

            LocalDate fecha = LocalDate.of(año, mes, dia);

            int cantidad = Integer.parseInt(  vista.getCantidad());

            String tipo = vista.getTipo();

            Factura factura = new Factura( asunto, fecha, cantidad, tipo );

            String error;

            if (editando) {

                int posicion = vista.getPosicionSeleccionada();

                if (posicion < 0) 
                {
                    avisarError("Selecciona una factura para actualizar.");
                    return;
                }

                error = gestor.actualizarFactura( posicion, factura );

                if (!error.equals("Sin errores")) {
                    avisarError(error);
                    return;
                }

                vista.actualizarFacturaLista(posicion, factura );
                editando = false;

            } else {

                error = gestor.añadirFactura(factura);

                if (!error.equals("Sin errores")) 
                {avisarError(error);
                return;
                }

                vista.añadirFacturaLista(factura);
            }

            vista.limpiarError();
            vista.limpiarCampos();

        } catch (NumberFormatException e) {

            avisarError("La cantidad debe ser un número entero" );

        } catch (DateTimeException e) {

            avisarError( "La fecha introducida no es válida.");
        }
    }


    public static void editarSeleccionada() {

        int posicion = vista.getPosicionSeleccionada();

        if (posicion < 0) {
            avisarError( "Selecciona una factura para editar.");
            return;
        }

        Factura factura = gestor.obtenerFactura(posicion);

        if (factura == null) {
            avisarError("No se ha encontrado la factura.");
            return;
        }

        vista.rellenarCampos(
                factura.getAsunto(),
                factura.getFecha().getDayOfMonth(),
                factura.getFecha().getMonthValue(),
                factura.getFecha().getYear(),
                String.valueOf(factura.getCantidad()),
                factura.getTipo()
        );

        editando = true;
        vista.limpiarError();
    }

 
    public static void eliminarSeleccionada() {

        int posicion = vista.getPosicionSeleccionada();

        if (posicion < 0) {
            avisarError("Selecciona una factura para eliminar.");
            return;
        }

        gestor.eliminarFactura(posicion);
        vista.eliminarFacturaLista(posicion);

        vista.limpiarCampos();
        vista.limpiarError();

        editando = false;
    }

    private static void avisarError(String error) {
        vista.mostrarError(error);
    }
}
