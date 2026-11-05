# 🗺️ Campus Route System (`routes_system`)

> Projeto acadêmico desenvolvido em **Linguagem C** com foco no estudo e aplicação de **Teoria de Grafos**.

---

## 🎯 Objetivo

O sistema foi idealizado para auxiliar alunos, professores e visitantes a navegarem e encontrarem rotas eficientes entre os prédios de um campus universitário.

O campus é representado matematicamente como um **grafo ponderado e não direcionado**, onde:

- **Vértices:** Representam os prédios do campus.
- **Arestas:** Representam os caminhos físicos entre dois prédios.
- **Pesos:** Correspondem à distância real em metros entre os locais conectados.

O software permite consultar conexões, calcular caminhos mínimos, verificar alcançabilidade global e exibir matrizes analíticas de navegação.

---

## 📋 Requisitos Funcionais

### 🗺️ RF01: Exibir o Mapa do Campus

Apresenta o mapeamento dos prédios e suas conexões estruturais, incluindo as distâncias entre eles.

> **Exemplo de visualização textual:**
>
> - 📍 Bloco B $\leftrightarrow$ Laboratório: `240 m`
> - 📍 Laboratório $\leftrightarrow$ Bloco A: `210 m`
> - 📍 Bloco A $\leftrightarrow$ Refeitório: `190 m`
> - 📍 Refeitório $\leftrightarrow$ Biblioteca: `280 m`
> - 📍 Biblioteca $\leftrightarrow$ Bloco A: `160 m`

---

### 📍 RF02: Encontrar a Menor Rota (Dijkstra)

A partir da entrada de um **prédio de origem** e um **prédio de destino**, o sistema aplica o **Algoritmo de Dijkstra** para determinar o caminho mais curto.

- **O programa exibe:**
  - A sequência detalhada de prédios percorridos.
  - A distância total da rota em metros.

---

### 🔍 RF03: Verificar Conectividade (Floyd-Warshall)

Verifica se existe rota entre dois prédios informados, independentemente de serem vizinhos diretos ou de exigirem conexões intermediárias. Utiliza para isso a matriz gerada pelo **Algoritmo de Floyd-Warshall**.

---

### 📊 RF04: Exibir a Matriz de Alcançabilidade

Apresenta uma matriz de adjacência/alcançabilidade indicando a acessibilidade entre todos os pares de prédios do campus.

- **Legenda da matriz:**
  - `1`: Existe caminho válido entre os prédios.
  - `0`: Não existe caminho entre os prédios.

---

### 💡 RF05: Experiência e Clareza nas Respostas

Garante que todas as interações com o usuário sejam informativas:

- Sempre exibe o trajeto passo a passo em vez de apenas o valor numérico final.
- Trata cenários de falha (como rotas inexistentes entre origem e destino isolados), informando o usuário claramente.
