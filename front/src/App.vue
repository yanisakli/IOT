<template>
  <div id="app">
    <div id="battery" v-if="battery">
      {{ battery }} % batterie
      <b-icon :icon="'battery-' + battery"></b-icon>
    </div>
    <div id="nav">
      <router-link to="/">Home</router-link> |
      <router-link to="/stats">Statistiques</router-link> |
      <router-link to="/messages">Messages</router-link> |
      <router-link to="/vocals">Vocals</router-link>
    </div>
    <transition
      name="fade"
      mode="out-in"
    >
      <router-view />
    </transition>
  </div>
</template>

<script>
  export default {
    data() {
      return {
        batteryPercentages: [10, 20, 30, 40, 50, 60, 70, 80, 90],
        battery: null
      }
    },
    created() {
      this.battery = this.randomPercentage()
    },
    methods: {
      randomPercentage() {
        return this.batteryPercentages[Math.floor(Math.random() * Math.floor(this.batteryPercentages.length))]
      }
    }
  }
</script>
<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

#nav {
  padding: 30px;
}

#nav a {
  font-weight: bold;
  color: #2c3e50;
}

#nav a.router-link-exact-active {
  color: #42b983;
}
</style>
