import java.util.Map;

public class Ricettario {
	private static Map<String,Integer> calorie=Map.of(
			"Uovo",155,
			"Farina",364,
			"Pomodoro",18,
			"Cipolla",40,
			"Funghi",387,
			"Parmigiano",431			
		);
	
	public static Preparato getPreparato(String nome) {
		return new Preparato(nome);
	}
	
	public static Ingrediente getIngrediente(String nome, int quantita) {
		return new Ingrediente(calorie.get(nome),quantita,nome);
	}
}
