
public class CheatBuster {

	public boolean check(Giocatore g) {
		for(String equip : g.getEquip())
		{
			if(equip=="sparacoccodrilli") {
				System.out.print(g.getNome()+" cheater\n");
				return false;
			}
		}
		return true;
	}
}
