<template>
  <div class="vocal">
    <h1 class="title">Vocal</h1>

    <p class="subtitle">Enregistrer votre message et envoyez le dans le coussin de votre partenaire</p>
    <div class="columns">
      <div class="column is-4 is-offset-4">
        <div class="recorder">
          <audio-recorder
                  :attempts="3"
                  :time="2"
                  :show-upload-button="false"
                  :before-recording="callback"
                  :pause-recording="callback"
                  :after-recording="callback"
                  :select-record="callback"
                  :before-upload="callback"
                  :successful-upload="callback"
                  :failed-upload="callback"/>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
  export default {
    name: "Vocal",
    methods: {
      callback (data) {
        console.debug(data)
      }
    }
  };
</script>

<style scoped>
  .recorder {
    display: flex;
    justify-content: center;
  }
</style>
