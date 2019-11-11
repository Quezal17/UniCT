//può sparare e imprecare


public class InPiedi implements Postura{
	
	@Override
	public void impreca()
	{
		System.out.println("Gli elfi non sanno usare la spada");		
	}
	
	@Override
	public void attacca()
	{
		System.out.println("BOOM ho fatto 50 danni");		
	}
	
	@Override
	public Postura up()
	{
		Postura p=new Salto();
		return p;
	}
	
	@Override
	public Postura down()
	{
		Postura p=new Accovacciato();
		return p;
	}
	


}
