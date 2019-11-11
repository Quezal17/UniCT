
public class TestPietanza {

	public static void main(String[] args) {
		Pietanza pasta=Ricettario.getPreparato("pasta");
		Pietanza farina=Ricettario.getIngrediente("Farina", 50);
		Pietanza uovo=Ricettario.getIngrediente("Uovo",2);
		pasta.add(farina);
		pasta.add(uovo);
		
		Pietanza salsa =Ricettario.getPreparato("salsa");
		Pietanza pomodoro=Ricettario.getIngrediente("Pomodoro", 50);
		Pietanza cipolla=Ricettario.getIngrediente("Cipolla",2);
		salsa.add(pomodoro);
		salsa.add(cipolla);
		
		Pietanza pastaSalsa=Ricettario.getPreparato("Pasta con la salsa");
		pastaSalsa.add(pasta);
		pastaSalsa.add(salsa);
		
		pastaSalsa.mostra();
	}

}
