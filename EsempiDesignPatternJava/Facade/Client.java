
public class Client {
	public static void main(String[] args) {
		String modalita="tutti contro tutti";
		Partite partita=new Partite(modalita);
		
		Giocatore g1=new Giocatore("g1",new String[] {"sparapatate","sparachiodi"});
		Giocatore g2=new Giocatore("g2",new String[] {"sparapolli","sparachiodi"});
		Giocatore g3=new Giocatore("g3",new String[] {"sparapatate","sparacoccodrilli"});
		Giocatore g4=new Giocatore("g4",new String[] {"sparabanane","sparachiodi"});
		
		partita.partecipa(modalita, g1);
		partita.partecipa(modalita, g2);
		partita.partecipa(modalita, g3);
		partita.partecipa(modalita, g4);
		
		partita.stampaServer();
	}
}
