import java.util.*;

public class Edificio {
private List<Spia> spie;

Edificio() {
	spie=new ArrayList<>();
}

public void inviaSpia(Spia spia) {
	if(!spie.contains(spia))
		spie.add(spia);
}

public void ritiraSpia(Spia spia) {
	if(spie.contains(spia))
		spie.remove(spia);
}

public void avvisaSpia() {
	for(Spia spia : spie)
	{
		spia.nuovoEroe();
	}
}

public void stampaSpie() {
	for(Spia spia : spie)
	{
		System.out.print(spia);
	}
}


}
