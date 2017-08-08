{
name: "GEO",
index: "world",
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "",
type: "tube",
r_max: 1000.0,
size_z: 1000.0,
position: [0.0, 0.0, 0.0],
material: "air",
color: [1.0, 0.0, 0.0, 0.1],
drawstyle: "solid"
}

{
name: "GEO",
index: "liner",
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "world",
type: "tube",
r_max: 999.0,
size_z: 499.0,
position: "air",
color: [1.0, 0.0, 0.0, 0.1],
drawstyle: "solid"
}


{
name: "GEO",
index: "inner_pmts",
enable: 1,
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "liner",
type: "pmtarray",
pmt_model: "r7081_led",
mu_metal: 1,
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner",
efficiency_correction: 9.000000e-01 ,
pos_table: "PMTINFO_inner",
orientation: "manual",
}


{
name: "GEO",
index: "inner_veto",
enable: 1,
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "liner",
type: "pmtarray",
pmt_model: "r7081_led",
mu_metal: 1,
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner",
efficiency_correction: 9.000000e-01 ,
pos_table: "PMTINFO_innerveto",
orientation: "manual",
}

{
name: "GEO",
index: "outer_veto",
enable: 1,
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "liner",
type: "pmtarray",
pmt_model: "r7081_led",
mu_metal: 1,
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/veto",
efficiency_correction: 9.000000e-01 ,
pos_table: "PMTINFO_outerveto",
orientation: "manual",
}

