public class Main {

    public static void main(String[] args) {

        Scuola scuola = new Scuola();

        
        Materia matematica = new Materia("Matematica", "MAT");
        Materia informatica = new Materia("Informatica", "INF");

        
        Studente studente1 = new Studente("Luca", "Rossi", "01/01/2005");

        
        Voto voto1 = new Voto("10/02/2024", matematica, 28);
        Voto voto2 = new Voto("15/02/2024", informatica, 30);

        
        studente1.aggiungiVoto(voto1);
        studente1.aggiungiVoto(voto2);

        
        Insegnante prof1 = new Insegnante("Marco", "Bianchi", "10/03/1980");

        
        prof1.aggiungiMateria(matematica);
        prof1.aggiungiMateria(informatica);

       
        scuola.aggiungiStudente(studente1);
        scuola.aggiungiInsegnante(prof1);

    }
}

