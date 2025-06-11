from typing import List, Optional

class Inventario:
    def __init__(self, capacidade_maxima: int = 10):
        self.itens: List[str] = []
        self.equipamentos: dict[str, dict] = {}  # Alterado para dict
        self.capacidade_maxima = capacidade_maxima
        self.slots = {
            'cabeca': None,
            'corpo': None,
            'maos': None,
            'pes': None,
            'acessorio': None
        }

    def adicionar_item(self, item: str, quantidade: int = 1) -> bool:
        """Adiciona um item ao inventário se houver espaço"""
        if len(self.itens) + quantidade > self.capacidade_maxima:
            print(f"Inventário cheio! Capacidade: {self.capacidade_maxima}")
            return False
        
        self.itens.extend([item] * quantidade)
        print(f"Adicionado {quantidade}x {item} ao inventário")
        return True

    def remover_item(self, item: str, quantidade: int = 1) -> bool:
        """Remove itens do inventário"""
        if self.itens.count(item) < quantidade:
            print(f"Item insuficiente: {item}")
            return False
            
        for _ in range(quantidade):
            self.itens.remove(item)
        print(f"Removido {quantidade}x {item}")
        return True

    def equipar_item(self, item: str, slot: str, atributos: dict) -> bool:
        """Equipa um item em um slot específico"""
        if slot not in self.slots:
            print(f"Slot inválido: {slot}")
            return False
            
        if self.slots[slot] is not None:
            print(f"Slot {slot} já ocupado por {self.slots[slot]}")
            return False
            
        self.slots[slot] = item
        self.equipamentos[slot] = {
            'item': item,
            'atributos': atributos
        }
        print(f"Equipado {item} no slot {slot}")
        return True

    def desequipar_item(self, slot: str) -> Optional[dict]:
        """Desequipa um item e retorna seus atributos"""
        if slot not in self.slots or self.slots[slot] is None:
            print(f"Nada equipado em {slot}")
            return None
            
        item_info = self.equipamentos.pop(slot)
        self.slots[slot] = None
        print(f"Desequipado {item_info['item']} de {slot}")
        return item_info

    def mostrar_inventario(self) -> None:
        """Exibe o conteúdo do inventário"""
        print("\n=== INVENTÁRIO ===")
        print(f"Capacidade: {len(self.itens)}/{self.capacidade_maxima}")
        
        if self.itens:
            print("\nItens:")
            for item in set(self.itens):
                print(f"- {item} x{self.itens.count(item)}")
        else:
            print("\nItens: Vazio")
        
        print("\nEquipamentos:")
        for slot, item in self.slots.items():
            print(f"- {slot.capitalize()}: {item if item else 'Vazio'}")