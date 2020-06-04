<template>
  <div class="stats">
    <h1 class="title">Statistiques</h1>

    <div class="columns">
      <div class="column is-6 is-offset-3">
        <b-table :data="data">
          <template slot-scope="props">
            <b-table-column field="id" label="ID" width="40" sortable numeric>
              {{ props.row.id }}
            </b-table-column>

            <b-table-column field="type" label="Type" sortable centered>
              <b-tag :type="props.row.type === 'Son' ? 'is-success' : 'is-primary'">{{ props.row.type }}</b-tag>
            </b-table-column>

            <b-table-column field="date" label="Date" :width="240" sortable centered>
              {{ props.row.date }}
            </b-table-column>

            <b-table-column field="apercu" label="Apercu" sortable centered>
              <template v-if="props.row.type === 'Son'">
                <b-button @click.prevent="playSound(getRandomSound())" icon-right="play" />
              </template>
              <template v-else>
                non disponile
              </template>
            </b-table-column>

            <b-table-column field="duration" label="Durée" sortable centered>
              <template v-if="props.row.type !== 'Son'">
                {{ props.row.duration }} ms
              </template>
              <template v-else>
                0 ms
              </template>
            </b-table-column>
          </template>
        </b-table>
      </div>
    </div>

  </div>
</template>

<script>
  export default {
    name: "Stats",
    data() {
      return {
        data: [
          { 'id': 1, 'type': 'Son', 'date': '2020-06-04 23:22:24', duration: 0},
          { 'id': 2, 'type': 'Mouvement', 'date': '2020-03-04 23:22:24', duration: this.getRandomNumber()},
          { 'id': 3, 'type': 'Mouvement', 'date': '2020-06-05 23:22:24', duration: this.getRandomNumber()},
          { 'id': 4, 'type': 'Son', 'date': '2020-06-05 23:22:24', duration: 0},
          { 'id': 5, 'type': 'Son', 'date': '2020-06-05 23:22:24', duration: 0},
          { 'id': 6, 'type': 'Mouvement', 'date': '2020-06-05 23:22:24', duration: this.getRandomNumber()},
          { 'id': 7, 'type': 'Son', 'date': '2020-06-05 23:22:24', duration: 0},
          { 'id': 8, 'type': 'Mouvement', 'date': '2020-06-05 23:22:24', duration: this.getRandomNumber()},
          { 'id': 9, 'type': 'Mouvement', 'date': '2020-06-05 23:22:24', duration: this.getRandomNumber()}
        ],
        sounds: [
          'http://soundbible.com/grab.php?id=114&type=mp3',
          'http://soundbible.com/grab.php?id=736&type=mp3',
          'http://soundbible.com/grab.php?id=796&type=mp3',
          'http://soundbible.com/grab.php?id=877&type=mp3'
        ]
      }
    },
    methods: {
      playSound (sound) {
        console.log('sound', sound)
        if(sound) {
          const audio = new Audio(sound);
          audio.play();
        }
      },
      getRandomSound() {
        return this.sounds[Math.floor(Math.random() * Math.floor(this.sounds.length))]
      },
      getRandomNumber() {
        return Math.floor(Math.random() * Math.floor(2000))
      }
    }
  };
</script>

<style scoped>
</style>
