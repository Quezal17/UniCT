import java.util.ArrayList;
import java.util.List;

public class Preparato extends Pietanza {
	private String nome;
	private List<Pietanza> list;
	
	
	Preparato(String nome) {
		this.nome = nome;
		this.list = new ArrayList<>();
	}

	@Override
	public void mostra() {
		System.out.print("#"+nome+"\n\t");
		list.forEach(x->x.mostra());
	}

	@Override
	public int calcolaCalorie() {
		return list.stream()
					.map(x->x.calcolaCalorie())
					.reduce(0, Integer::sum);
	}

	@Override
	public void add(Pietanza p) {
		list.add(p);
	}

	@Override
	public void remove(Pietanza p) {
		list.remove(p);
	}

}
