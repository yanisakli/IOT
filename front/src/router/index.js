import Vue       from "vue";
import VueRouter from "vue-router";
import Alarm     from "../views/Alarm.vue";
import Stats     from "../views/Stats.vue";
import Vocal     from "../views/Vocal.vue";
import Message   from "../views/Message.vue";
import Music     from '../views/Music'

Vue.use(VueRouter);

const routes = [
  {
    path: "/",
    name: "Alarm",
    component: Alarm
  },
  {
    path: "/stats",
    name: "Stats",
    component: Stats
  },
  {
    path: "/vocals",
    name: "Vocal",
    component: Vocal
  },
  {
    path: "/messages",
    name: "message",
    component: Message
  },
  {
    path: "/music",
    name: "music",
    component: Music
  }
];

const router = new VueRouter({
  mode: "history",
  base: process.env.BASE_URL,
  routes
});

export default router;
