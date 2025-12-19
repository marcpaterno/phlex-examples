{
  source: {
    plugin: 'generate_layers',
    layers: {
      event: { parent: "job", total: 10, starting_number: 1 }
    }
  },
  modules: {
    add_cpp: {
      plugin: 'module',
    },
    # Write "sum" data product to output file
    output: {
      plugin: 'form_module',
      products: ["sum"]
    },
  },
}
