[README.md](https://github.com/user-attachments/files/31854355/README.md)
# NexusEther# Nexus Ether Starter

Protótipo inicial em Unreal Engine 5 + C++ para um jogo de mundo aberto focado em batalhas e criação de poderes.

## O que já existe

- Personagem base
- Sistema de Éter
- Éter máximo e atual
- Regeneração de Éter
- Consumo de Éter
- Habilidades com:
  - custo
  - intensidade
  - duração
  - cooldown
  - multiplicador de condição
- Exemplo de habilidade ofensiva
- Estrutura pronta para expansão

## Ideia central

O jogador não escolhe apenas um poder pronto. Cada habilidade pode ser definida por parâmetros:

`Poder = Intensidade × Duração × Alcance × Multiplicador de condição`

Quanto mais poderosa a habilidade, maior o custo de Éter e/ou as restrições.

## Como usar

1. Crie um projeto C++ no Unreal Engine 5 chamado `NexusEther`.
2. Feche o Unreal Editor.
3. Copie as pastas `Source` e `Config` deste repositório para o projeto.
4. Gere novamente os project files.
5. Compile o projeto.
6. Crie um Blueprint baseado em `ANexusCharacter`.
7. Configure os inputs para:
   - MoveForward
   - MoveRight
   - Ability1

## Próximos passos

- Sistema de faca e armas
- Ten / ocultação / reforço
- Editor modular de habilidades
- Condições e juramentos
- PvP
- Replicação multiplayer
- NPCs mestres
- Progressão de maestria
- Inventário
- Mundo aberto

## Licença

Protótipo de estudo. Você pode adaptar e expandir.
