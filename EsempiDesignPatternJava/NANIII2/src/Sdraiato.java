//può solo sparare

public class Sdraiato implements Postura{
	
	@Override
	public void attacca()
	{
		System.out.println("BOOM ho fatto 200 danni");		
	}
	
	@Override
	public void impreca()
	{
		System.out.println("Ho finito gli insulti");		
	}
	
	@Override
	public Postura up()
	{
		Postura p=new Accovacciato();
		return p;
	}
	
	@Override
	public Postura down()
	{
		Postura p=new Salto();
		return p;
	}
}
