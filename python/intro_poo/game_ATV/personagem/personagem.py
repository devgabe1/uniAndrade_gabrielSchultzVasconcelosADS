from .inventario import Inventario

class PersonagemGame:
    def __init__(self, nome: str, vida: int, forca: int, nivel: int, classe: str):
        self.nome = nome
        self.vida = vida
        self.forca = forca
        self.nivel = nivel
        self.classe = classe
        self.inventario = Inventario()

    def atacar(self, alvo: 'PersonagemGame') -> None:
        dano = self.forca * self.nivel
        alvo.vida -= dano
        print(f"{self.nome} atacou {alvo.nome} causando {dano} de dano!")
    
    def usar_item(self, item: str) -> None:
        if item in self.inventario:
            print(f"{self.nome} usou {item}!")
            self.inventario.remove(item)
        else:
            print(f"{item} não encontrado no inventário!")
    
    def adicionar_item(self, item: str, quantidade: int = 1) -> None:
        self.inventario.adicionar_item(item, quantidade)
    
    def equipar_item(self, item: str, slot: str, atributos: dict) -> None:  # Alterado para dict
        if item in self.inventario.itens:
            if self.inventario.equipar_item(item, slot, atributos):
                self.inventario.remover_item(item)
                # Aplica atributos do equipamento
                if 'forca' in atributos:
                    self.forca += atributos['forca']
                if 'vida' in atributos:
                    self.vida += atributos['vida']
        else:
            print(f"{self.nome} não possui {item} no inventário!")

    def mostrar_status(self) -> None:
        print(f"\n=== Status de {self.nome} ===")
        print(f"Classe: {self.classe}")
        print(f"Nível: {self.nivel}")
        print(f"Vida: {self.vida}")
        print(f"Força: {self.forca}")
        self.inventario.mostrar_inventario()


