from gensim.summarization import summarize
text = "Solid-state nanopores currently suffer from the drawback, however, that the channel constituting the pore is long, ∼100 times the distance between two bases in a DNA molecule (0.5 nm for single-stranded DNA). This paper[5] provides proof of concept that it is possible to realize and use ultrathin nanopores fabricated in graphene monolayers for single-molecule DNA translocation. As individual DNA molecules translocate through the pore, characteristic temporary conductance changes are observed in the ionic current through the nanopore, setting the stage for future single-molecule genomic screening devices. In a typical solid-state nanopore in say a 30 nm thick membrane, the current blockade resulting from DNA translocation is due to a large number of bases (∼100) present in the pore. Fabrication of nanopores in graphene layers was reported previously in the vacuum of a transition electron microscope  but graphene nanopore devices that ionically probe the translocation of single molecules were so far not realized. Indeed, theoretical calculations of DNA translocation through a nanopore in graphene have already indicated the possibility for single-base resolution by probing the translocating molecule electrically in the transverse direction by use of the intrinsic conductive properties of graphene. Subsequently, they mounted the pore into a microfluidic flow cell, add a 1 M saline solution (1 M KCl, room temperature, pH 8.0) on both sides of the graphene membrane, and measure current-voltage (I-V) curves from ion transport through the graphene nanopore. They measured DNA translocations on seven graphene nanopores (monolayer and multilayer graphene membranes with pore diameters ranging from 10 to 25 nm) and collected good statistics on three devices (two monolayers and an eight-layer multilayer with pore diameters of 22, 25, and 24 nm, respectively). The average translocation time is 2.7 ± 0.8 ms for the unfolded DNA, a value that is similar, albeit slightly larger, to that for solid-state nanopores in a 20 nm SiN membrane for which the translocation time is 1.2 ± 0.3 ms under the same applied voltage of 200 mV and for a similar pore diameter. We note that the translocation time is expected to be independent of the membrane thickness because the driving electrostatic force is the same: in a thinner membrane, the electric field over the graphene pore is higher (same voltage applied over a shorter distance) which however is exactly compensated by the smaller number of charges present on the piece of the DNA molecule that resides in the pore. While these pinholes increase the baseline ion current signal and associated noise, they do not otherwise hinder the ability of our devices to measure DNA translocation through the fabricated nanopores. The thinner membrane decreases the overall pore resistance, therefore increasing the magnitude of the current blocked by the translocating DNA molecule. An ionic current-voltage measurement of a 10 nm diameter nanopore in graphene coated with 5 nm TiO2 is shown in Figure 3a, along with a TEM image of the nanopore inset. For this device we estimate, based on open pore currents and relative nanopore size, that the total pinhole area is 0.08% of the total suspended graphene area. They found that the current blocked by DNA translocation through graphene nanopores is larger than what has been observed for SiN nanopores of the same diameter, due to the thinness of the graphene membrane. We present a theoretical model where hydrodynamic drag on the section of the polymer outside the pore is the dominant force counteracting the electrical driving force. At the heart of the setup is a solid-state nanopore device that has been fabricated by shrinking a 20-50 nm pore in silicon oxide in a transmission electron microscope to a final diameter of 10 nm.9 Based on tilting experiments inside the TEM, we estimate that the typical depth of our nanopores is on the order of 20 nm, much shorter than the detected molecules."
print(summarize(text,ratio = 0.6))
# print(text)