
public class Server {
private int capienzaMax;
private int giocatori;
private String modalita;
private int livello;

Server(int cmax,String m,int l) {
	capienzaMax=cmax;
	modalita=m;
	livello=l;
	giocatori=0;
}

public void incrementa() {
	if(giocatori!=capienzaMax)
		giocatori++;
}

public void decrementa() {
	if(giocatori!=0)
		giocatori--;
}

@Override
public String toString() {
	return "Modalità: "+modalita+", Livello: "+livello+", Giocatori: "+giocatori+"/"+capienzaMax;
}

public boolean notFull() {
	if(giocatori==capienzaMax)
		return false;
	else
		return true;
}

public String getMod() {
	return modalita;
}

}
