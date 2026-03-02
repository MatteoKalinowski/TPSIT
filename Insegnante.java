import java.util.ArrayList;
import java.util.List;

public class Insegnante extends Persona {

    private List<Materia> materie = new ArrayList<>();

    public Insegnante(String nome, String cognome, String dataDiNascita) {
        super(nome, cognome, dataDiNascita);
    }

    public void aggiungiMateria(Materia materia) {
        materie.add(materia);
    }
}
