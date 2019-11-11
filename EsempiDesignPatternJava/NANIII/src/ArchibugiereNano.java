//lo stato viene tenuto all'interno del context

public class ArchibugiereNano {
private Postura p=new InPiedi();
public void spara() {p.attacca();}
public void insultaElfo() {p.impreca();}
public void alza() {
	switch(p.getName())
	{
		case "Salto": p=new Sdraiato(); break;
		case "InPiedi": p=new Salto(); break;
		case "Accovacciato": p=new InPiedi(); break;
		case "Sdraiato": p=new Accovacciato(); break;
	}
}
public void abbassa() {
	
	switch(p.getName())
	{
		case "Salto": p=new InPiedi(); break;
		case "InPiedi": p=new Accovacciato(); break;
		case "Accovacciato": p=new Sdraiato(); break;
		case "Sdraiato": p=new Salto(); break;
	}
	
}
}


//alza e abbassa sono i metodi che permettono di cambiare lo stato