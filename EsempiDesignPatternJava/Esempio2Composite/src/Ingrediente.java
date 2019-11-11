
public class Ingrediente extends Pietanza {
	private int calorie;
	private int quantita;
	private String nome;
	
	Ingrediente(int calorie, int quantita, String nome) {
		this.calorie = calorie;
		this.quantita = quantita;
		this.nome = nome;
	}

	@Override
	public void mostra() {
		System.out.format("\t- %dg %s (%d kcal per 100g)\n\t",quantita,nome,calorie);
	}

	@Override
	public int calcolaCalorie() {
		return calorie*(quantita/100);
	}

}
