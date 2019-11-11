import java.util.*;

public class SpiaGilda implements Spia {
private List<Eroe> targets;
private Taverna t;
private String nome;
private TipoEroe tipo;

	SpiaGilda(String nome, TipoEroe tipo, Taverna t){
		this.nome=nome;
		this.tipo=tipo;
		this.t=t;
		targets=new ArrayList<>();
	}
	
	public void nuovoEroe() {
		List<Eroe> temp=t.getEroi();
		
		for(Eroe eroe : temp)
		{
			if(!targets.contains(eroe) && eroe.getTipo()==tipo)
			{
				targets.add(eroe);
			}
		}		
	}
	
	@Override
	public String toString() {
		return "Nome:"+nome+" Tipo:"+tipo+" NumeroEroi:"+targets.size()+"\n";
	}
}
