<template>
  <div id="app">
    <h1>Consultas do Banco de Dados: Fórmula 1</h1>
    
    <div v-for="(consulta, index) in consultas" :key="index">
      <Consulta :data="consulta.data" :title="consulta.title" :description="consulta.description"/>
    </div>

    <h3>Grupo 8:<br> João Pedro Mendes Alves Bianco 120064499 
                <br> Julia Lopes Da Rocha 119137336 
                <br> Leonardo Fonseca Dos Santos 121124569 
                <br> Maria Carolina Boudreaux Ramirez Deleito 121172871
    </h3>
  </div>
</template>

<script>
import Consulta from "./components/Consulta.vue";

export default {
  name: "App",
  components: {
    Consulta,
  },
  data() {
    return {
      consultas: [
        { title: "Consulta 1: Pilotos e Equipes", description:"Lista os pilotos e suas respectivas equipes (junção interna)", data: [] },
        { title: "Consulta 2: Corridas e Circuitos", description:"Lista todas as corridas realizadas, incluindo circuitos sem corridas associadas (junção externa)", data: [] },
        { title: "Consulta 3: Equipes e Total de Pilotos", description:"Lista as equipes com a quantidade total de pilotos contratados (função de agregação com agrupamento)", data: [] },
        { title: "Consulta 4: Resultados de Pilotos", description:"Lista os resultados de pilotos em corridas específicas", data: [] },
        { title: "Consulta 5: Circuitos e Média de Rodadas", description:"Determina circuitos utilizados em múltiplas rodadas e sua média", data: [] },
      ],
    };
  },
  async mounted() {
    // Busca os dados para cada consulta
    for (let i = 1; i <= 5; i++) {
      const response = await fetch(`http://127.0.0.1:5000/consulta${i}`);
      const data = await response.json();
      this.consultas[i - 1].data = data;
    }
  },
};
</script>

<style>
#app {
  font-family: Arial, sans-serif;
  text-align: center;
  margin: 20px;
}
</style>
