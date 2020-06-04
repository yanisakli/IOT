<template>
  <div class="alarm">
    <div class="columns">
      <div class="column">{{ currentTime }}</div>
    </div>

    <div v-if="alarmValidated" class="columns">
      <div class="column">{{ alarm }}</div>
    </div>

    <div class="columns">
      <div class="column is-4 is-offset-4">
        <b-button v-if="alarmValidated" type="is-danger">Supprimer</b-button>
        <b-collapse v-if="!alarmValidated" :open="false">
          <button class="button is-primary" slot="trigger">Add alarm</button>
          <b-datetimepicker
            v-model="alarm"
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
import { addSeconds } from "date-fns";

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
      } else {
        alert('Date is empty');
      }
    }
  }
};
</script>

<style scoped>
.m-top {
  margin-top: 10px;
}
</style>
