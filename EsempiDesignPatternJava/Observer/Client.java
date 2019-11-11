
public class Client {
	
	public static void main(String[] args) {
		Taverna t=new Taverna();		
		
		Spia s1=new SpiaGilda("spia1",TipoEroe.GUERRIERO,t);
		Spia s2=new SpiaGilda("spia2",TipoEroe.MAGO,t);
		Spia s3=new SpiaGilda("spia3",TipoEroe.LADRO,t);
		
		t.inviaSpia(s1);
		t.inviaSpia(s2);
		t.inviaSpia(s3);
		
		Eroe e1=new Eroe("e1",TipoEroe.GUERRIERO);
		Eroe e2=new Eroe("e2",TipoEroe.MAGO);
		Eroe e3=new Eroe("e3",TipoEroe.LADRO);
		Eroe e4=new Eroe("e4",TipoEroe.GUERRIERO);
		
		t.entra(e1);
		t.entra(e2);
		t.entra(e3);
		t.entra(e4);
		
		t.stampaSpie();
	}
}
