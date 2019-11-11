import java.util.*;

public class Taverna extends Edificio {
private List<Eroe> eroi;

	Taverna(){
		eroi=new ArrayList<>();
	}
	
public void entra(Eroe e) {
	eroi.add(e);
	super.avvisaSpia();
}
	
public List<Eroe> getEroi() {
	return eroi;
}

}
