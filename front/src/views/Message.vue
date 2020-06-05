<template>
  <div class="messages">
    <h1 class="title">Message</h1>

    <p class="subtitle">Ecouter tout vos messages</p>
    <div class="columns">
      <div class="column is-6 is-offset-3">
        <b-table :data="messages">
          <template slot-scope="props">
            <b-table-column field="id" label="ID" width="40" sortable numeric>
              {{ props.row.id }}
            </b-table-column>

            <b-table-column field="date" label="Date" :width="240" sortable centered>
              {{ props.row.date }}
            </b-table-column>

            <b-table-column field="apercu" label="Apercu" centered>
                <b-button @click.prevent="playSound(musicUrl)" :icon-right="musicIcon" />
            </b-table-column>
          </template>
        </b-table>
      </div>
    </div>
  </div>
</template>

<script>
  export default {
    name: "Message",
    data() {
      return {
        messages: [
          { 'id': 1, 'date': '2020-06-04 23:22:24'},
          { 'id': 2, 'date': '2020-06-05 23:22:24'},
          { 'id': 3, 'date': '2020-06-06 23:22:24'},
        ],
        musicIcon: 'play',
        messageStart: false,
        musicUrl: 'http://soundbible.com/grab.php?id=114&type=mp3',
        audio: null
      }
    },
    methods: {
      playSound (sound) {
        if(sound) {
          if (this.messageStart) {
            this.audio.pause()
            this.messageStart = false
            this.musicIcon = 'play'
            return
          }
          this.audio = new Audio(this.musicUrl);
          this.audio.play();
          this.messageStart = true
          this.musicIcon = 'pause'
        }
      }
    }
  };
</script>

<style scoped>
</style>
