import "./DeviceCard.css"
import Axios from "axios"
import {useState, useEffect} from 'react'


export default function DeviceCard() {
const [Componet, setComponent] = useState([])


useEffect(() =>{ Axios.get("http://localhost:3001/")
.then(res => {
  setComponent(res.data)
})
  },[Componet])

useEffect(() =>{ Axios.get("http://localhost:3001/")
  .then(res => {
    setComponent(res.data)
    const database = JSON.stringify(res.data).toString();
    Axios.post(`http://192.168.1.7:2244`, database)
    .then(res => {
      console.log("Data sent successfully:", res.data);
    })
    .catch(error => {
      console.error("Error sending data:", error);
      // Handle error gracefully (e.g., display message to user)
    });
  // .then(res => {
  //   console.log(res.data);
  // })
  })
  },[])

//const Componet = [{identifier:"1", name:"led1", status:true},{identifier:"2", name:"led2", status:false} ]

const handleCardClick = (cmp) => {
  try {
    console.log("id is ", cmp.identifier);
    Axios.get(`http://localhost:3001/device/${cmp.identifier}`)
      .then((response) => {
        console.log("Data sent successfully:", response.data);
        setComponent([...Componet], response.data);
        window.location.reload();
      })
      .catch((e) => {
        console.log(e);
      });
  } catch (e) {
    console.log("error", e);
  }
};

const colorlist = Componet.map((cmp) => {
    return (
      <div
        key={cmp.identifier}
        className="card-list"
        onClick={() => {
          handleCardClick(cmp);
        }}
      >
        <h1 className="card-item">
          <h3>
            <span
              style={{
                // fontSize: "30px",
                // width: "20px",
                // height: "20px",
                display: "inline",
                width: "20px",
                height: "20px",
                backgroundColor: "transparent",
              }}
            >
              {cmp.identifier}
            </span>{" "}
            {cmp.name}
          </h3>
          <div className="status">
            <span>status</span>
            <div
              className="arrow"
              style={{ backgroundColor: cmp.status ? "green" : "red" }}
            >
              {" "}
            </div>
          </div>
        </h1>
      </div>
    );
  })
  return (
    <>
      <div style={{ marginTop: "20px" ,marginRight:"500px"}}>{colorlist}</div>
      </>
  )
};