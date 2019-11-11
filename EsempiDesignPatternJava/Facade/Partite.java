
public class Partite {
private CheatBuster cb;
private ListaUtenti lu;
private Server s;

	Partite(String modalita) {
		cb=new CheatBuster();
		lu=new ListaUtenti();
		s=new Server(10,modalita,2);
	}
	
public void partecipa(String modalita, Giocatore g) {
	if(cb.check(g) && s.getMod()==modalita && s.notFull())
	{
		lu.registra(g);
		s.incrementa();
		System.out.print(g.getNome()+" registrato con successo\n");
	}
	else {
	System.out.print(g.getNome()+" Errore nella registrazione, ricontrolla i requisiti\n");
	}
}

public void stampaServer() {
	System.out.print(s.toString());
}

}
