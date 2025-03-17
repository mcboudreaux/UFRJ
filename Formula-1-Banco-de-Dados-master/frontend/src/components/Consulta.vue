<template>
    <div class="consulta">
      <h2>{{ title }}</h2>
      <h3>{{ description }}</h3>
      <table>
        <thead>
          <tr>
            <th v-for="(header, index) in headers" :key="index">{{ header }}</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(row, index) in data" :key="index">
            <td v-for="(value, key) in row" :key="key">{{ value }}</td>
          </tr>
        </tbody>
      </table>
    </div>
  </template>
  
  <script>
  export default {
    props: {
      data: { type: Array, default: () => [] },
      title: { type: String, default: "" },
      description: { type: String, default: "" },
    },
    computed: {
      headers() {
        return this.data.length > 0 ? Object.keys(this.data[0]) : [];
      },
    },
  };
  </script>
  
  <style>
  .consulta {
    margin: 20px 0;
  }
  
  table {
    width: 100%;
    border-collapse: collapse;
  }
  
  th,
  td {
    border: 1px solid #ddd;
    padding: 8px;
    text-align: left;
  }
  </style>
  