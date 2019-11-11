//le decisioni non vengono prese qui, ma nelle singole classi

public class ArchibugiereNano {
private Postura p=new InPiedi();
public void spara() {p.attacca();}
public void insultaElfo() {p.impreca();}
public void alza() {p=p.up();}
public void abbassa() {p=p.down();}
}

//alza e abbassa sono i metodi che permettono di cambiare lo stato