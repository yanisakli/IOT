<template>
  <div class="content">
    <h1 class="title">Music</h1>

    <p class="subtitle">Choissisez votre propre musique au réveil !</p>
    <div class="columns">
      <div class="column is-6 is-offset-3">
        <b-table :data="musics">
          <template slot-scope="props">
            <b-table-column field="id" label="ID" width="40" sortable numeric>
              {{ props.row.id }}
            </b-table-column>

            <b-table-column field="titre" label="Titre" sortable centered>
              <b-tag>{{ props.row.title }}</b-tag>
            </b-table-column>

            <b-table-column field="artist" label="Artiste" :width="240" sortable centered>
              {{ props.row.artist }}
            </b-table-column>

            <b-table-column field="play">
              <b-button @click.prevent="playSound(musicUrl)" :icon-right="musicIcon" />
            </b-table-column>
            <b-table-column field="Selection" label="Selection">
              <b-radio v-model="radio"
                       :native-value="props.row.title"
                       name="name">
              </b-radio>
            </b-table-column>
          </template>
        </b-table>
      </div>
    </div>

  </div>
</template>

<script>
  export default {
    name: "Music",
    data() {
      return {
        musics: [
          { 'id': 1, 'title': 'Off Course', 'artist': 'Migos'},
          { 'id': 2, 'title': 'Gooba', 'artist': '6ix9ine'},
          { 'id': 3, 'title': "La vie d'artiste", 'artist': 'Cristophe Maé'},
        ],
        radio: null,
        musicUrl: 'https://files.freemusicarchive.org/storage-freemusicarchive-org/music/WFMU/Broke_For_Free/Directionless_EP/Broke_For_Free_-_01_-_Night_Owl.mp3',
        musicStart: false,
        musicIcon: 'play',
        audio: null

      }
    },
    methods: {
      playSound (sound) {
        if(sound) {
          if (this.musicStart) {
            this.audio.pause()
            this.musicStart = false
            this.musicIcon = 'play'
            return
          }
          this.audio = new Audio(this.musicUrl);
          this.audio.play();
          this.musicStart = true
          this.musicIcon = 'pause'
        }
      }
    }
  };
</script>

<style scoped>
</style>
