//può solo imprecare

public class Salto implements Postura{

	@Override
	public void impreca()
	{
		System.out.println("La mia Piccina");		
	}
	
	@Override
	public void attacca()
	{
		System.out.println("ho finito i colpi");
	}
	
	@Override
	public Postura up()
	{
		Postura p=new Sdraiato();
		return p;
	}
	
	@Override
	public Postura down()
	{
		Postura p=new InPiedi();
		return p;
	}
}
