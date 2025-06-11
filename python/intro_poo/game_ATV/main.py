from personagem.personagem import PersonagemGame


# Criando personagens
heroi = PersonagemGame(nome="Aragorn", vida=100, forca=15, nivel=5, classe="Guerreiro")
vilao = PersonagemGame(nome="Sauron", vida=150, forca=20, nivel=8, classe="Mago Negro")

# Adicionando itens
heroi.adicionar_item("Espada Andúril")
heroi.adicionar_item("Poção de Cura", 3)
heroi.adicionar_item("Armadura de Mithril", 1)

# Equipando itens
heroi.equipar_item(
    item="Espada Andúril",
    slot="maos",
    atributos={"forca": 10, "vida": 5}
)

heroi.equipar_item(
    item="Armadura de Mithril",
    slot="corpo",
    atributos={"vida": 20}
)

heroi.mostrar_status()