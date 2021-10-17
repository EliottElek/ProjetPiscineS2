function stringToColor(string) {
  let hash = 0;
  let i;

  /* eslint-disable no-bitwise */
  for (i = 0; i < string.length; i += 1) {
    hash = string.charCodeAt(i) + ((hash << 5) - hash);
  }

  let color = '#';

  for (i = 0; i < 3; i += 1) {
    const value = (hash >> (i * 8)) & 0xff;
    color += `00${value.toString(16)}`.substr(-2);
  }
  /* eslint-enable no-bitwise */

  return color;
}

export default function stringAvatar(name, width, height) {
  if (width === undefined || height === undefined){
    return {
      sx: {
        bgcolor: stringToColor(name),
        color:"white",
      },
      children: `${name.split(' ')[0][0]}${name.split(' ')[1][0]}`,
    };
  }
  return {
    sx: {
      bgcolor: stringToColor(name),
      color:"white",
      width: width,
      height: height,
      margin: "10px" 
    },
    children: `${name.split(' ')[0][0]}${name.split(' ')[1][0]}`,
  };
}