<template>
  <div class="alarm">
    <div class="columns">
      <div class="column">
        <div class="columns">
          <div class="column">
            <h1 class="title">{{ getTime() }}</h1>
          </div>
        </div>
        <div class="columns">
            <div class="column">
              <h3 class="subtitle">{{ getFullDate() }}</h3>
            </div>
        </div>
      </div>
    </div>

    <div v-if="alarmValidated">
      <div class="columns">
        <h2 class="column title">Reveil</h2>
      </div>
      <div class="columns">
        <div class="column clock">{{ getFullDateTimeClock() }}</div>
      </div>
    </div>

    <div class="columns">
      <div class="column is-4 is-offset-4">
        <b-button v-if="alarmValidated" type="is-danger" class="m-top" @click="deleteTime()">Supprimer</b-button>
        <b-collapse v-if="!alarmValidated" :open="false">
          <button class="button is-primary" slot="trigger">Ajout d'un reveil</button>
          <b-datetimepicker
            v-model="alarm"
            :min-datetime="currentTime"
            class="m-top"
            rounded
            placeholder="Click to select..."
            icon="calendar-today"
            horizontal-time-picker
          ></b-datetimepicker>
          <button class="button is-success m-top" @click="validateAlarm()">Valider</button>
        </b-collapse>
      </div>
    </div>
  </div>
</template>

<script>
import { addSeconds, format } from "date-fns";
import { fr } from 'date-fns/locale'

export default {
  data() {
    return {
      currentTime: new Date(),
      alarm: null,
      alarmValidated: false,
      intervalId: null
    };
  },
  created() {
    console.log("[ALARM] mounted called");
    this.intervalId = setInterval(this.updateTime, 1000);
  },
  destroyed() {
    console.log("[ALARM] destroy called");
    clearInterval(this.intervalId);
  },
  methods: {
    updateTime() {
      console.log("[ALARM] updateTime called");
      this.currentTime = addSeconds(this.currentTime, 1);
    },
    validateAlarm() {
      if(this.alarm) {
        this.alarmValidated = true;
        // Send http request to backend api with the alarm as a parameter
      } else {
        alert('Date is empty');
      }
    },
    deleteTime() {
      this.alarm = null;
      this.alarmValidated = false;
      // Send http request to backend api to delete alarm
    },
    getTime() {
      return format(this.currentTime, 'HH:mm:ss');
    },
    getFullDate() {
      return format(this.currentTime, 'EEEE d MMMM', { locale: fr });
    },
    getFullDateTimeClock() {
      return format(this.alarm, 'EEEE d MMMM HH:mm', { locale: fr });
    }
  }
};
</script>

<style scoped>
.m-top {
  margin-top: 10px;
}
</style>
