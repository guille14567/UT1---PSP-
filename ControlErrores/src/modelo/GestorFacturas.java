
package modelo;

import java.time.LocalDate;
import java.util.ArrayList;

public class GestorFacturas {

    private ArrayList<Factura> listaFacturas = new ArrayList<>();

    public String añadirFactura(Factura factura) {

        if (factura == null) {
            return "La factura no es válida.";}

        String asunto = factura.getAsunto();

        if (asunto == null|| asunto.length() < 1|| asunto.length() > 10) {
            return "El asunto debe tener entre 1 y 10 caracteres.";
        }

   
        for (Factura f : listaFacturas) {

            if (f.getAsunto().equalsIgnoreCase(asunto)) {

                return "Asunto repetido.";
            }
        }

        
        if (factura.getFecha() == null|| factura.getFecha().isBefore(LocalDate.of(2000, 1, 1))) {
            return "La fecha no puede ser anterior al 1/1/2000.";
        }

       
        if (factura.getCantidad() == null|| factura.getCantidad() < 0) {
            return "La cantidad debe ser mayor o igual que 0.";
        }

        listaFacturas.add(factura);

        return "Sin errores";
    }

    public String actualizarFactura(
            int posicion, Factura factura) {

        if (posicion < 0|| posicion >= listaFacturas.size()) {
            return "Selecciona una factura válida.";
        }

        if (factura == null) {
            return "La factura no es válida.";}

        String asunto = factura.getAsunto();

        if (asunto == null|| asunto.length() < 1|| asunto.length() > 10) {
            return "El asunto debe tener entre 1 y 10 caracteres.";
        }

      
        for (int i = 0; i < listaFacturas.size(); i++) {
            if (i != posicion && listaFacturas.get(i).getAsunto().equalsIgnoreCase(asunto)) {
                return "Asunto repetido.";
            }
        }

        if (factura.getFecha() == null|| factura.getFecha().isBefore( LocalDate.of(2000, 1, 1))) {
            return "La fecha no puede ser anterior al 1/1/2000.";
        }

        if (factura.getCantidad() == null || factura.getCantidad() < 0) {
            return "La cantidad debe ser mayor o igual que 0.";
        }
        listaFacturas.set(posicion, factura);
        return "Sin errores";
    }

    public Factura obtenerFactura(int posicion) {

        if (posicion < 0|| posicion >= listaFacturas.size()) {
           return null;
        }
        return listaFacturas.get(posicion);
    }
    
    public void eliminarFactura(int posicion) {

        if (posicion >= 0  && posicion < listaFacturas.size()) {
            listaFacturas.remove(posicion);
        }
    }
}
