import Vue from "vue";
import Buefy from "buefy";
import App from "./App.vue";
import router from "./router";
import "buefy/dist/buefy.css";
import AudioRecorder from 'vue-audio-recorder'

Vue.config.productionTip = false;

Vue.use(AudioRecorder)
Vue.use(Buefy);

new Vue({
  router,
  render: h => h(App)
}).$mount("#app");
