<template>
  <div id="app">
    <div id="power-status">
      <template v-if="power">
        <div class="is-vcentered">
          <b-icon icon="power" type="is-success"></b-icon>
          <span>Allumé</span>
        </div>
        <div id="battery" v-if="battery">
          {{ battery }} % batterie
          <b-icon :icon="'battery-' + battery"></b-icon>
        </div>
      </template>
      <template v-else>
        <div>
          <b-icon icon="power" type="is-danger"></b-icon>
          <span>Eteint</span>
        </div>
      </template>
    </div>
    <div id="nav">
      <router-link to="/">Home</router-link> |
      <router-link to="/stats">Statistiques</router-link> |
      <router-link to="/messages">Messages</router-link> |
      <router-link to="/vocals">Vocals</router-link> |
      <router-link to="/music">Music</router-link>
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
        power: true,
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

  #power-status {
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin: auto;
    width: 230px;
  }
</style>
