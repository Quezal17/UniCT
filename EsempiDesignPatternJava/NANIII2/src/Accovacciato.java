//può solo sparare e imprecare

public class Accovacciato implements Postura{
	
	@Override
	public void impreca()
	{
		System.out.println("Orecchie a punta");
	}
	
	@Override
	public void attacca()
	{
		System.out.println("BOOM ho fatto 100 danni");		
	}
	
	@Override
	public Postura up()
	{
		Postura p=new InPiedi();
		return p;
	}
	
	@Override
	public Postura down()
	{
		Postura p=new Sdraiato();
		return p;
	}
	
}
