enum TipoEroe{GUERRIERO,MAGO,LADRO}
public class Eroe {
private String nome;
private TipoEroe tipo;

	Eroe(String n,TipoEroe t){
		nome=n;
		tipo=t;
	}

public String getNome() {
	return nome;
}

public TipoEroe getTipo() {
	return tipo;
}

}
