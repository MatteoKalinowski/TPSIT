import java.util.ArrayList;
import java.util.List;

public class Studente extends Persona {

    private List<Voto> voti = new ArrayList<>();

    public Studente(String nome, String cognome, String dataDiNascita) {
        super(nome, cognome, dataDiNascita);
    }

    public void aggiungiVoto(Voto voto) {
        voti.add(voto);
    }

    public List<Voto> getVoti() {
        return voti;
    }
}
