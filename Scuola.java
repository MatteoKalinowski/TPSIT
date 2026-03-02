import java.util.ArrayList;
import java.util.List;

public class Scuola {

    private List<Studente> studenti = new ArrayList<>();
    private List<Insegnante> insegnanti = new ArrayList<>();

    public void aggiungiStudente(Studente studente) {
        studenti.add(studente);
    }

    public void aggiungiInsegnante(Insegnante insegnante) {
        insegnanti.add(insegnante);
    }
}
