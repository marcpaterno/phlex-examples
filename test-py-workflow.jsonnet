{
  driver: {
    cpp: 'generate_layers',
  },
  sources: {
    numbers_source: {
      cpp: 'numbers_source',
      layer: 'job',
    },
  },
  modules: {
    subtract: {
      py: 'subtract',
      input: ['i', 'j'],
      output: ['difference'],
    },
    // Python data products cannot yet be written to output files
    //   output: {
    //     cpp: 'form_module',
    //     products: [],
    //   },
  },
}
