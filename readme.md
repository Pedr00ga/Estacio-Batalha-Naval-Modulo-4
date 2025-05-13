# 🧊 Tabuleiro com Habilidades Especiais em C

Este programa cria um tabuleiro 10x10 representando um jogo de navios, onde navios são posicionados horizontal e verticalmente. Ele também sobrepõe três tipos de habilidades especiais (Cone, Cruz e Octaedro) sobre o tabuleiro, destacando áreas de efeito.

## 🔧 Requisitos

* Compilador C instalado (como `gcc`)
* Terminal ou prompt de comando

## 📁 Arquivo

Salve o código em um arquivo com extensão `.c`. Exemplo:

```bash
tabuleiro.c
```

## 🛠️ Como Compilar

No terminal, execute:

```bash
gcc tabuleiro.c -o tabuleiro
```

> Isso cria um executável chamado `tabuleiro`.

## ▶️ Como Executar

No terminal:

```bash
./tabuleiro
```

> No Windows, use:

```cmd
tabuleiro.exe
```

## 🧩 Legenda do Tabuleiro

* `0` → Água
* `3` → Navio
* `5` → Área afetada por habilidades (Cone, Cruz ou Octaedro)

## 🧠 Habilidades Especiais

Cada habilidade afeta uma área 3x5 no tabuleiro:

* **Cone**: forma triangular apontando para baixo
* **Cruz**: formato de cruz com centro no meio
* **Octaedro**: forma losangular (como um diamante frontal)
