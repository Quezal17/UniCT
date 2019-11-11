import java.util.*;

public class ListaUtenti {
private List<String> giocatori; 

ListaUtenti(){
giocatori=new ArrayList<>();
}

public void registra(Giocatore g) {
	if(!giocatori.contains(g.getNome()))
	{
		giocatori.add(g.getNome());
	}
}

public void rimuovi(Giocatore g) {
	if(giocatori.contains(g.getNome()))
	{
		giocatori.remove(g.getNome());
	}
}

}
