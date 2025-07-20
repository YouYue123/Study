const express = require('express');
const cors = require('cors');
const helmet = require('helmet');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(helmet());
app.use(cors());
app.use(express.json());

// Health check endpoint
app.get('/health', (req, res) => {
  res.status(200).json({
    status: 'healthy',
    timestamp: new Date().toISOString(),
    environment: process.env.NODE_ENV || 'development',
    pod: process.env.HOSTNAME || 'unknown'
  });
});

// Main API endpoint
app.get('/api/hello', (req, res) => {
  res.json({
    message: 'Hello from EKS!',
    timestamp: new Date().toISOString(),
    pod: process.env.HOSTNAME || 'unknown',
    environment: process.env.NODE_ENV || 'development'
  });
});

// Root endpoint
app.get('/', (req, res) => {
  res.json({
    message: 'Welcome to the EKS Sample App',
    version: '1.0.0',
    endpoints: {
      health: '/health',
      api: '/api/hello'
    },
    pod: process.env.HOSTNAME || 'unknown'
  });
});

// Error handling middleware
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).json({
    error: 'Something went wrong!',
    message: err.message
  });
});

// 404 handler
app.use('*', (req, res) => {
  res.status(404).json({
    error: 'Route not found',
    availableRoutes: ['/', '/health', '/api/hello']
  });
});

app.listen(PORT, '0.0.0.0', () => {
  console.log(`Server is running on port ${PORT}`);
  console.log(`Health check available at http://localhost:${PORT}/health`);
  console.log(`API endpoint available at http://localhost:${PORT}/api/hello`);
}); 