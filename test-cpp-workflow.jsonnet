{
  driver: {
    cpp: 'generate_layers',
    layers: {
      spill: { parent: 'job', total: 10, starting_number: 1 },
    },
  },
  sources: {
    numbers_source: {
      cpp: 'numbers_source',
      layer: 'spill',
    },
  },
  modules: {
    add_cpp: {
      cpp: 'add_and_verify',
      layer: 'spill',
    },
    // Write "sum" data product to output file
    output: {
      cpp: 'form_module',
      products: ['sum'],
    },
  },
}
