const fs = require("fs");

function decodeYValue(value, base) {
  return parseInt(value, base);
}



function parseJSONInput(filename) {
  const rawData = fs.readFileSync(filename);
  const data = JSON.parse(rawData);
  return data;
}

function lagrangeInterpolation(roots) {
  let constantTerm = 0;
  const n = roots.length;

  for (let i = 0; i < n; i++) {
    let term = roots[i].y;
    for (let j = 0; j < n; j++) {
      if (i !== j) {
        term *= roots[j].x / (roots[j].x - roots[i].x);
      }
    }
    constantTerm += term;
  }

  return constantTerm;
}

function main() {
  const filename = "test_cases.json";
  const data = parseJSONInput(filename);

  const roots = data.map((root) => {
    const x = parseInt(root.key);
    const y = decodeYValue(root.value, root.base);
    return { x, y };
  });

  const constantTerm = lagrangeInterpolation(roots);
  console.log("The constant term (c) of the polynomial is:", constantTerm);
}

main();
