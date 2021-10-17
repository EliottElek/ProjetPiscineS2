// // dummy data to make frontend
const user = {
  id: 2329439432,
  firstname: "Eliott",
  lastname: "Morcillo",
  avatarUrl: "https://avatars.githubusercontent.com/u/64375473?v=4",
  chatList: [
    {
      name: "Les misérables",
    },
    {
      name: "TD03 SI inter",
    },
  ],
  conversations: [
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Thomas",
          lastname: "Pujol",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>La database c'est vraiment chaud...</p>",
          createdAt: "16:02",
        },
        {
          userId: 2329439432,
          body: "<p>J'ai pas le temps</p>",
          createdAt: "16:01",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Jean",
          lastname: "Delasalle",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 2329439432,
          body: "<p>Frais</p>",
          createdAt: "12:44",
        },
        {
          type: "media",
          userId: 30238430334,
          body: "<img style = 'width: 100%; height:100%; border-radius: 10px'  src ='data:image/jpeg;base64,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' alt = 'pic'/>",
          createdAt: "8:12",
        },
        {
          userId: 2329439432,
          type: "media",
          body: "<iframe style = 'width: 100%; height:100%; border-radius: 10px' src='https://www.youtube.com/embed/y881t8ilMyc' frameborder='0' allowfullscreen></iframe>",
          createdAt: "8:13",
        },
        {
          userId: 30238430334,
          body: "<p>T'as pas fermé la porte ce matin</p>",
          createdAt: "12:44",
        },
        {
          userId: 2329439432,
          body: "<p>Pourquoi t'étais vener ?</p>",
          createdAt: "12:23",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Pierre",
          lastname: "Lebrebis",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          type: "media",
          userId: 2329439432,
          body: "<img style = 'width: 100%; height:100%; border-radius: 10px' src ='https://www.tracedirecte.com/uploads/Image/45/IMF_WEBZINE/GAB_TRACEDIRECTE/5392_648_paysage-serengeti-tanzanie.jpg' alt = 'pic'/>",
          createdAt: "8:13",
        },
        {
          userId: 30238430334,
          body: "<p>Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Quisque sit amet dictum ex, vitae posuere mi. Quisque mattis hendrerit varius. Aenean ut faucibus sapien. Donec quis ullamcorper orci, eu congue augue. Suspendisse vehicula at leo et posuere.</p>",
          createdAt: "8:12",
        },
        {
          type: "media",
          userId: 30238430334,
          body: "<img style = 'width: 100%; height:100%; border-radius: 10px'  src ='data:image/jpeg;base64,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' alt = 'pic'/>",
          createdAt: "8:12",
        },
        {
          userId: 2329439432,
          body: "<p>C'était bien ?</p>",
          createdAt: "8:01",
        },
        {
          userId: 2329439432,
          body: "<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus commodo magna ligula, sit amet placerat elit volutpat nec. In vel metus eu ipsum consectetur euismod nec in leo. Pellentesque egestas, risus id ornare sodales, massa dui porttitor erat, sit amet aliquet libero diam a justo. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Quisque sit amet dictum ex, vitae posuere mi. Quisque mattis hendrerit varius. Aenean ut faucibus sapien. Donec quis ullamcorper orci, eu congue augue. Suspendisse vehicula at leo et posuere. Sed accumsan, lacus fringilla aliquam feugiat, mauris sapien ornare mauris, nec euismod sapien felis nec leo.</p>",
          createdAt: "7:56",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Thomas",
          lastname: "Pujol",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>La database c'est vraiment chaud...</p>",
          createdAt: "16:02",
        },
        {
          userId: 2329439432,
          body: "<p>J'ai pas le temps</p>",
          createdAt: "16:01",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Jean",
          lastname: "Delasalle",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>T'as pas fermé la porte ce matin</p>",
          createdAt: "12:44",
        },
        {
          userId: 2329439432,
          body: "<p>Pourquoi t'étais vener ?</p>",
          createdAt: "12:23",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Pierre",
          lastname: "Lebrebis",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>Ouais c'était vraiment cool</p>",
          createdAt: "8:12",
        },
        {
          userId: 2329439432,
          body: "<p>C'était bien hier ?</p>",
          createdAt: "8:01",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Thomas",
          lastname: "Pujol",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>La database c'est vraiment chaud...</p>",
          createdAt: "16:02",
        },
        {
          userId: 2329439432,
          body: "<p>J'ai pas le temps</p>",
          createdAt: "16:01",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Jean",
          lastname: "Delasalle",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>T'as pas fermé la porte ce matin</p>",
          createdAt: "12:44",
        },
        {
          userId: 2329439432,
          body: "<p>Pourquoi t'étais vener ?</p>",
          createdAt: "12:23",
        },
      ],
    },
    {
      id: 23122121324,
      open: false,
      users: [
        {
          id: 30238430334,
          firstname: "Pierre",
          lastname: "Lebrebis",
          avatarUrl: "",
        },
      ],
      messages: [
        {
          userId: 30238430334,
          body: "<p>Ouais c'était vraiment cool</p>",
          createdAt: "8:12",
        },
        {
          userId: 2329439432,
          body: "<p>C'était bien hier ?</p>",
          createdAt: "8:01",
        },
        {
          userId: 2329439432,
          body: "<p>salut bg</p>",
          createdAt: "8:12",
        },
      ],
    },
  ],
};
// const user = {
//   id: 2329439432,
//   firstname: "Eliott",
//   lastname: "Morcillo",
//   avatarUrl: "",
//   chatList: [],
//   conversations: [],
// };
export default user;
