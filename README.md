# Sistema de Gestão de Filas em Supermercado

Este projeto é um sistema de gestão de filas desenvolvido em linguagem **C**. O objetivo é simular a organização e o atendimento de clientes em caixas de um supermercado, oferecendo um serviço eficiente e justo. O sistema implementa filas com prioridade para atendimento preferencial a idosos, gestantes e pessoas com deficiência, utilizando estruturas de dados e listas encadeadas.

---

## 📋 Especificações do Trabalho

- **Estruturas de Dados Utilizadas:**

  - **Cliente:**
    - Nome (até 100 caracteres)
    - CPF (11 dígitos)
    - Prioridade (1: Alta, 2: Média, 3: Baixa)
    - Número de itens no carrinho
  - **Caixa:**
    - Número de identificação do caixa
    - Estado do caixa (Aberto ou Fechado)
  - **FilaPrioridade:**
    - Lista encadeada para gerenciar clientes organizados por prioridade

- **Número de Caixas:**

  - O sistema inicia com 5 caixas abertos.
  - Não é possível adicionar mais caixas.
  - Caixas podem ser abertos ou fechados durante a execução.
  - Clientes de caixas fechados são realocados automaticamente.

- **Operações Disponíveis no Sistema:**
  1. **Cadastrar Cliente:** Solicita dados como nome, CPF, prioridade, número de itens e caixa de destino.
  2. **Atender Cliente:** Remove o cliente de maior prioridade da fila do caixa especificado.
  3. **Abrir Caixa:** Muda o estado de um caixa para aberto.
  4. **Fechar Caixa:** Fecha o caixa e realoca os clientes para outros caixas abertos.
  5. **Imprimir Lista de Clientes:** Exibe os clientes em espera em cada caixa, organizados por prioridade.
  6. **Imprimir Status dos Caixas:** Mostra o estado de cada caixa (Aberto ou Fechado) e o número de clientes na fila.
  7. **Sair:** Encerra o sistema.

---

## 🕰️ Estrutura do Projeto

```
Sistema-Gestao-de-Supermercado/
├── include/
│   ├── cliente.h           # Declaração da estrutura Cliente e suas funções
│   ├── caixa.h             # Declaração da estrutura Caixa e suas funções
│   ├── fila_prioridade.h   # Declaração da FilaPrioridade e funções relacionadas
│   ├── utils.h             # Funções utilitárias para validação de dados
├── src/
│   ├── cliente.c           # Implementação das funções de Cliente
│   ├── caixa.c             # Implementação das funções de Caixa
│   ├── fila_prioridade.c   # Implementação das funções de FilaPrioridade
│   ├── utils.c             # Implementação das funções utilitárias
│   ├── main.c              # Ponto de entrada do sistema
├── Makefile                # Script de automação para compilação
└── README.md               # Documentação do projeto
```

---

## 🛠️ Como Compilar e Executar

### **Pré-requisitos**

- Compilador `gcc` instalado.
- Sistema operacional compatível com ferramentas de linha de comando.

### **Passo a Passo**

1. Clone este repositório:
   ```bash
   git clone https://github.com/seuusuario/sistema-gestao-de-filas.git
   ```
2. Navegue até o diretório do projeto:
   ```bash
   cd sistema-gestao-de-filas
   ```
3. Compile o projeto utilizando o Makefile:
   ```bash
   make
   ```
4. Execute o sistema:
   ```bash
   make run
   ```
5. Para limpar os arquivos compilados:
   ```bash
   make clean
   ```

---

## 🚀 Funcionalidades

### **1. Cadastrar Cliente**

- Solicita os seguintes dados:
  - Nome
  - CPF (11 dígitos)
  - Prioridade (1: Alta, 2: Média, 3: Baixa)
  - Número de itens no carrinho
  - Número do caixa (1-5)
- Valida os dados antes do cadastro.

### **2. Atender Cliente**

- Remove o cliente de maior prioridade da fila de um caixa.
- Exibe os dados do cliente atendido.

### **3. Abrir Caixa**

- Altera o estado de um caixa para "Aberto".

### **4. Fechar Caixa**

- Altera o estado de um caixa para "Fechado".
- Realoca os clientes da fila do caixa fechado para outros caixas abertos.

### **5. Imprimir Lista de Clientes**

- Exibe os clientes em espera em cada caixa, organizados por prioridade.

### **6. Imprimir Status dos Caixas**

- Mostra o estado de cada caixa e a quantidade de clientes em espera.

### **7. Sair**

- Encerra o programa.

---

## 📖 Exemplos de Uso

### **Cadastro de Cliente**

```
Nome: João
CPF: 12345678901
Prioridade (1: Alta, 2: Média, 3: Baixa): 1
Numero de itens no carrinho: 10
Caixa (1-5): 2
Cliente cadastrado com sucesso no caixa 2.
```

### **Atendimento de Cliente**

```
Caixa para atendimento (1-5): 2
Cliente atendido:
Nome: João
CPF: 12345678901
Prioridade: 1
Itens no carrinho: 10
```

### **Fechamento de Caixa**

```
Fechar caixa (1-5): 2
Caixa 2 fechado. Clientes realocados para caixas abertos.
```

---

## 🖋️ Observações Importantes

- Caso todos os caixas estejam fechados, o sistema não permitirá o cadastro de novos clientes.
- O sistema exige que os dados do cliente sejam válidos antes de serem cadastrados.

---

## 👨‍💻 Autor

Este projeto foi desenvolvido como parte do curso de Engenharia de Computação no **CEFET-MG**, para a disciplina **Tópicos Especiais em Fundamentos da Engenharia de Computação**.

**Professor Orientador:** Tiago Alves de Oliveira
